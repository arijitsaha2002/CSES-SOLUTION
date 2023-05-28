# import difflib

# strings = ['hello','money_sum','code.cpp']

# world = 'Money Sum'

# print(difflib.get_close_matches(world,strings))

import os

curr_path = str(os.getcwd()).split('/')

Section = curr_path[-2]
problem = curr_path[-1]

print(Section, problem)