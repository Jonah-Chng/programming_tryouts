import comparator as cp
import pandas as pd

###############################################################################################
#   Code only parses the column 'Activity', you can choose the column you want in line 52     #
###############################################################################################
print ('Data before running the regex')
data = {'Number': [x+1 for x in range(10)] ,
        'Activity': ['Collect Medication', 'Explain to patient','Request for more time',  
            'Key in patient\'s ridiculous demands','Discuss whats the purpose of life is','Taking a break from life',
            ' Take blood pressure', 'document','confirm',
            'Throw rubbish patient\'s NOK in trash'],
        }
df = pd.DataFrame(data, columns = ['Number','Activity'])
print (df)

###############################################################################################
#   Parsing each line in csv, searching it with Regex, assigning each activity with a category
###############################################################################################

output_category = []
category_matches=[]
category_keys = []

def _parse_line(line, index):
    """
    Do a regex search against all defined regexes and
    return the key and match result of the first matching regex
    """

    ####################################################################################
    #   Assign a category to each task, currently this is set to one category per item #
    ####################################################################################
    for key, rx in cp.rx_dict_category.items():
        for item in rx:
            match = item.search(line)
            if not match:
                continue
            if match:
                return key, match

    # Check if regex matched in the line, if there are no matches
    if not category_matches:
        print('Could not find match in activity number',index,'!')
        return None, None
    
total = 0
count = 0

for index, row in df.iterrows():
    category_keys, category_matches= _parse_line(row['Activity'], index) # <---- Choose the column you want here
    total +=1
    
    if category_keys:
        output_category.append(category_keys) 
        count +=1
    elif not category_keys:
        output_category.append(None)


print('Total lines processed: '+str(round(count/total*100,2)) + '%')
# Stick the categories back onto the dataframes
cat = pd.DataFrame(output_category, columns = ['Category'])
df = pd.concat([df, cat], axis = 1)


print()
print('Data after running the regex')
print(df)