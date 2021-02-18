import re

#####################################################
# Categories of activties:
# - Moving (walk, go, collect)
# - Action (check, collect, educate)
# - location (pharmacy, AMC, MC (medicine cabinet))
#####################################################

rx_dict_category = {
    'preperation': ( 
        re.compile(r'check',re.IGNORECASE),
        re.compile(r'collect\smedication',re.IGNORECASE),
        re.compile(r'go\sto\strolley',re.IGNORECASE),
        re.compile(r'taking\sover',re.IGNORECASE),
        re.compile(r'prepare|preparation',re.IGNORECASE),
        re.compile(r'case\snotes',re.IGNORECASE),
        re.compile(r'update',re.IGNORECASE),
        re.compile(r'(|restock)\s(medical|medicine|medication)\scabinet',re.IGNORECASE),
        re.compile(r'linen\sroom',re.IGNORECASE),
        re.compile(r'AMC',re.IGNORECASE),
        re.compile(r'get',re.IGNORECASE),
        re.compile(r'room\s',re.IGNORECASE),
        re.compile(r'nurses\station',re.IGNORECASE),
        re.compile(r'wear',re.IGNORECASE),
        re.compile(r'store\sroomt',re.IGNORECASE),
        re.compile(r'hand(|\s)off',re.IGNORECASE),
        re.compile(r'observation',re.IGNORECASE),
        re.compile(r'medical\sequipment\sstorage',re.IGNORECASE),
    ),
    'patient education':(
        re.compile(r'(patient|educate|enlighten|explain)\s(NOK|education|to|for|patient(|s))(|\s|\spatient|\sNOK)',re.IGNORECASE),
    ),
    'direct patient care':(
        re.compile(r'request\sfor',re.IGNORECASE),
        re.compile(r'prop\spatient',re.IGNORECASE),
        re.compile(r'ecg',re.IGNORECASE),
        re.compile(r'covidien',re.IGNORECASE),
        re.compile(r'(|put|place|give|break)\s(|\w+|\w\w|\w\w\w)\s(for|to|for\sthe|to\sthe)\spatient',re.IGNORECASE),
        re.compile(r'scan\sbarcode\sof\spatient(|s)',re.IGNORECASE),
        re.compile(r'remove',re.IGNORECASE),
        re.compile(r'rubbish',re.IGNORECASE),
        re.compile(r'trash',re.IGNORECASE),
        re.compile(r'hook\sup',re.IGNORECASE),
        re.compile(r'throw',re.IGNORECASE),
        re.compile(r'take',re.IGNORECASE),
        re.compile(r'configure',re.IGNORECASE),
        re.compile(r'replace',re.IGNORECASE),
        re.compile(r'insert',re.IGNORECASE),
        re.compile(r'tuck',re.IGNORECASE),
        re.compile(r'help',re.IGNORECASE),
        re.compile(r'grab',re.IGNORECASE),
        re.compile(r'pharmacy',re.IGNORECASE),
        re.compile(r'tidy$|tidy',re.IGNORECASE),
        re.compile(r'bed$|bed',re.IGNORECASE),
        re.compile(r'assist',re.IGNORECASE),
        re.compile(r'administration',re.IGNORECASE),
        re.compile(r'administer',re.IGNORECASE),
        re.compile(r'tie\sup',re.IGNORECASE),
        re.compile(r'adjust',re.IGNORECASE),
        re.compile(r'perform',re.IGNORECASE),
        re.compile(r'VSM',re.IGNORECASE),
        re.compile(r'shift\spatient',re.IGNORECASE),
        re.compile(r'take\sblood\spressure',re.IGNORECASE),
    ),
    'documentation':(
        re.compile(r'key(|\w+)\s',re.IGNORECASE),
        re.compile(r'citrix \s',re.IGNORECASE),
        re.compile(r'document',re.IGNORECASE),
    ),
    'discussion':(
        re.compile(r'discuss',re.IGNORECASE),
        re.compile(r'confirm',re.IGNORECASE),
        re.compile(r'colleague',re.IGNORECASE),
        re.compile(r'nurse',re.IGNORECASE),
        re.compile(r'phone',re.IGNORECASE),
        re.compile(r'find\sout',re.IGNORECASE),
        re.compile(r'doctor',re.IGNORECASE),
    ),
    'break':(
        re.compile(r'taking\sa\sbreak\s',re.IGNORECASE),
    )
}