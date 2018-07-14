import subprocess
import threading
import time

condaPath = "/media/divar/01D0EA3EF660B7F0/UBUNTUFiles/Anaconda/bin/python3.6"


class PacManGame(threading.Thread):
    def __init__(self):
        self.stdout = None
        self.stderr = None
        threading.Thread.__init__(self)

    def run(self):
        p = subprocess.call('../pacManForked/buildDirectory/pacMan', shell=True)
        # self.stdout, self.stderr = p.communicate()


class SpeechRecognition(threading.Thread):
    def __init__(self):
        self.stdout = None
        self.stderr = None
        threading.Thread.__init__(self)

    def run(self):
        p = subprocess.call('cd ../speechRecognition && ' +
                            condaPath + ' speechRecognition.py', shell=True)
        self.stdout, self.stderr = p.communicate()


speechRecognition = SpeechRecognition()
speechRecognition.start()
time.sleep(2)
pacManGame = PacManGame()
pacManGame.start()

pacManGame.join()
