#/usr/bin/env python3
import argparse
import json
from pprint import pprint

parser = argparse.ArgumentParser()
parser.add_argument("fleet_config_file", nargs=1)
args = parser.parse_args()

with open(args.fleet_config_file[0], 'r') as f:
    fleet_config = json.load(f)

pprint(fleet_config)