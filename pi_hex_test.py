import os
import random

TEST_COUNT = 10
TEST_LENGTH = 10
tests = '' 

DATA_FILE = './test/data.txt'
PI_HEX_EXE = './build/pi_hex'
PI_HEX_OUTPUT = './output/pi_hex.txt'
OUTPUT_FILE = lambda st,ed: f'output/test_result_{st}_{ed}.txt'

if __name__ == '__main__':
    #get start and end from input
    TEST_START = int(input("Start=")) 
    TEST_END = int(input("End=")) 
    
    file = open(DATA_FILE, 'r')
    real_content = file.read()
    file.close()
    print('start')

    for i in range(TEST_COUNT):
        print(f'test {i}')
        #start from 1
        st = random.randint(TEST_START,TEST_END)
        ed = st + TEST_LENGTH
        #print(f'{st}, {ed}')
        #Run pi_hex
        os.system(f'{PI_HEX_EXE} {st} {ed}')
        file = open(PI_HEX_OUTPUT, 'r')
        test_content = file.read()
        file.close()

        #check if content is right
        st -= 1
        tests += f'[{st + 1}, {ed}]\ntest: {test_content}\nreal: {real_content[st:ed]}\n\n'
    
    file = open(OUTPUT_FILE(TEST_START, TEST_END), 'w')
    file.write(tests)
    file.close()




