#!/usr/bin/env python3

# Find use cases of each level of logging here:
# https://docs.python.org/3/howto/logging.html

import logging

# To get directory path and current working directory
import os 
dir_path = os.path.dirname(os.path.realpath(__file__))
cwd = os.getcwd()
print('File path is %s current working directory is %s \n' % (dir_path, cwd))

# Logging to a file
print('\nLogging to a file')
logging.basicConfig(filename=cwd+'/example.log', level=logging.WARNING, format='%(levelname)s %(asctime)s %(message)s')
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')
logging.error('And non-ASCII stuff, too, like Øresund and Malmö')

# Logging levels
print('\nLogging levels')
logging.debug('Detailed info, of interest when diagnosing problems')
logging.info('Confirmation things are working correctly')
logging.warning('Indication of a problem in near future. Use Warn when client can do something, Warning when he cannot')
logging.error('More serious problem, and the software couldnt accomplish a task')
logging.critical('Serious error. Indicate the program is unable to continue running')