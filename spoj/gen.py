import random
import string

# print ''.join(random.choice(string.ascii_lowercase) for x in range(250000))
# print ''.join(random.choice(string.ascii_lowercase) for x in range(250000))
for i in range(10):
    print ''.join('a' for x in range(100000))
