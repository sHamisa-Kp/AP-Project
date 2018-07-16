import subprocess
import threading
import time

#condaPath = "/home/shamisa/anaconda3/bin/python3.6"
condaPath = "/media/divar/01D0EA3EF660B7F0/UBUNTUFiles/Anaconda/bin/python3.6"


class PacManGame(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        p = subprocess.call('../pacManForked/'
                            'build-pacMan-Desktop_Qt_5_11_0_GCC_64bit-Debug/pacMan', shell=True)


class SpeechRecognition(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        p = subprocess.call('cd ../speechRecognition && ' +
                            condaPath + ' speechRecognition.py', shell=True)


speechRecognition = SpeechRecognition()
speechRecognition.start()
time.sleep(8)
pacManGame = PacManGame()
pacManGame.start()

pacManGame.join()
