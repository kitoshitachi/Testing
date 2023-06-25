import os
os.chdir(os.path.dirname(__file__))

for i in range(1,13):
    os.system(f'ex_03 < testcase/{i}.in > result/{i}.out')
    os.system(f'gcov -b -c -f ex_03.c > report/{i}.txt')

    os.remove("ex_03.gcda")