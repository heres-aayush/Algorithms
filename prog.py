import sys
import time

for i in range(100):
    row = "="*i + ">"
    sys.stdout.write("%s\r%d%%" %(row, i + 1))
    sys.stdout.flush()
    time.sleep(1)

sys.stdout.write("\n")