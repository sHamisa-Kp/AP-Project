# Copyright 2017 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import pyautogui
import time
import subprocess
from ctypes import *
import tensorflow as tf
import pyaudio
import wave
import math
import audioop
import os
# from numba import jit

""" Recording Specs """
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 16000
CHUNK = 1024
RECORD_SECONDS = 0.85
num_samples = 50

"""Error Handling"""
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'


# from tensorflow.contrib.framework.python.ops import audio_ops as contrib_audio
def py_error_handler(filename, line, function, err, fmt):
    pass


def measureAudioIntensity():
    p = pyaudio.PyAudio()

    stream = p.open(format=FORMAT, channels=CHANNELS, rate=RATE, input=True, frames_per_buffer=CHUNK)
    recData = stream.read(CHUNK)

    r = math.sqrt(abs(audioop.avg(recData, 4)))
    # print("r: {}" .format(r))

    stream.close()
    p.terminate()
    # print(r)
    return r


def load_graph(filename):
    """Unpersists graph from file as default graph."""
    with tf.gfile.FastGFile(filename, 'rb') as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())
        tf.import_graph_def(graph_def, name='')


def load_labels(filename):
    """Read in labels, one label per line."""
    return [line.rstrip() for line in tf.gfile.GFile(filename)]


def run_graph(wav_data, labels, input_layer_name, output_layer_name,
              num_top_predictions):
    """Runs the audio data through the graph and prints predictions."""
    with tf.Session() as sess:
        # Feed the audio data as input to the graph.
        #   predictions  will contain a two-dimensional array, where one
        #   dimension represents the input image count, and the other has
        #   predictions per class
        softmax_tensor = sess.graph.get_tensor_by_name(output_layer_name)
        predictions, = sess.run(softmax_tensor, {input_layer_name: wav_data})

        # Sort to show labels in order of confidence
        top_k = predictions.argsort()[-num_top_predictions:][::-1]
        for node_id in top_k:
            human_string = labels[node_id]
            score = predictions[node_id]
            if score < 0.25:
                break
            print('%s (score = %.5f)' % (human_string, score))
            if human_string == 'go':
                pyautogui.press('p')
                pyautogui.press('space')
                break
            elif human_string == 'stop':
                pyautogui.press('p')
                break
            elif human_string == 'off':
                pyautogui.press('esc')
                break
            else:
                for s in ['up', 'down', 'left', 'right']:
                    if human_string == s:
                        pyautogui.press(s)
                        break
        return 0


def label_wav(wav, labels, graph, input_name, output_name, how_many_labels):
    """Loads the model and labels, and runs the inference to print predictions."""
    if not wav or not tf.gfile.Exists(wav):
        tf.logging.fatal('Audio file does not exist %s', wav)
    if not labels or not tf.gfile.Exists(labels):
        tf.logging.fatal('Labels file does not exist %s', labels)
    if not graph or not tf.gfile.Exists(graph):
        tf.logging.fatal('Graph file does not exist %s', graph)

    labels_list = load_labels(labels)
    load_graph(graph)

    """Warning Handler for libasound"""
    ERROR_HANDLER_FUNC = CFUNCTYPE(None, c_char_p, c_int, c_char_p, c_int, c_char_p)
    c_error_handler = ERROR_HANDLER_FUNC(py_error_handler)
    asound = cdll.LoadLibrary('libasound.so')
    asound.snd_lib_error_set_handler(c_error_handler)

    """Measure Noise Intensity"""
    print("Measuring Noise...")
    intensityArr = []
    for i in range(30):
        # t0 = time.time()
        intensityArr.append(measureAudioIntensity())
        # print(time.time() - t0)
    tmpArr = sorted(intensityArr, reverse=True)
    noiseIntensityAverage = sum(tmpArr[:int(0.2 * len(tmpArr))]) / int(0.2 * len(tmpArr))
    print("noiseAverage: {}".format(noiseIntensityAverage))

    # start Recording
    p = pyaudio.PyAudio()
    prev_data0 = []
    prev_data1 = []
    prev_data2 = []
    prev_data3 = []
    prev_data4 = []
    INTENSITY = noiseIntensityAverage * 2.3
    #INTENSITY = 2100
    print("INTENSITY: {}".format(INTENSITY))
    print("TimeElapsed: {}".format(time.time() - startTime))
    print("Ready!\n\n")
    while True:
        stream = p.open(format=FORMAT, channels=CHANNELS, rate=RATE, input=True, frames_per_buffer=CHUNK)
        recData = stream.read(CHUNK)
        # print("recData: {}".format(recData))
        r = math.sqrt(abs(audioop.avg(recData, 4)))
        # print("r: {}".format(r))

        if r > INTENSITY:
            print(' recording... Average audio intensity is r', r)
            # t0 = time.time()
            frames = [prev_data0, prev_data1, prev_data2, prev_data3, prev_data4, recData]
            for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
                frames.append(stream.read(CHUNK))
            # print(time.time() - t0)
            print('finished recording')

            waveFile = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
            waveFile.setnchannels(CHANNELS)
            waveFile.setsampwidth(p.get_sample_size(FORMAT))
            waveFile.setframerate(RATE)
            waveFile.writeframes(b''.join(frames))
            # print("b''.join(frames): {}".format(b''.join(frames)))

            waveFile.close()
            with open(wav, 'rb') as wav_file:
                wav_data = wav_file.read()
            run_graph(wav_data, labels_list, input_name, output_name, how_many_labels)
        prev_data0 = prev_data1
        prev_data1 = prev_data2
        prev_data2 = prev_data3
        prev_data3 = prev_data4
        prev_data4 = recData
        stream.stop_stream()
        stream.close()
    p.terminate()


if __name__ == '__main__':
    # subprocess.call('pulseaudio --kill', shell=True)
    # subprocess.call('pulseaudio --start', shell=True)
    # subprocess.call('jack_control exit', shell=True)
    # subprocess.call('jack_control start', shell=True)
    startTime = time.time()

    WAVE_OUTPUT_FILENAME = "file.wav"
    labelFileName = "conv_actions_labels.txt"
    graphFileName = "conv_actions_frozen.pb"
    how_many_labels = 1

    label_wav(WAVE_OUTPUT_FILENAME, labelFileName, graphFileName, "wav_data:0",
              "labels_softmax:0", how_many_labels)
