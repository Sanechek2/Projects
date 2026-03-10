def lbs_to_kg(weight):
    return weight * 0.453592

def kg_to_lbs(weight):
    return weight / 0.453592

def max(num):
    maximum = num[0]
    for x in num:
        if x > maximum:
            maximum = x
    return maximum