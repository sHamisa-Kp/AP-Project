import pyautogui
import subprocess
import threading
import time


class PacManGame(threading.Thread):
    def __init__(self):
        self.stdout = None
        self.stderr = None
        threading.Thread.__init__(self)

    def run(self):
        p = subprocess.call('../pacManForked/buildDirectory/pacMan', shell=True)
        self.stdout, self.stderr = p.communicate()


pacManGame = PacManGame()
pacManGame.start()
time.sleep(5)
while True:
    pyautogui.press('left')
myclass.join()
