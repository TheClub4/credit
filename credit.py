while True:
    number = int(input("Please enter your card number: "))
    if number > 0:
        break

# Store digits in a list
digits = list(str(number))

# If there is an invalid number of digits
if len(digits) != 13 and len(digits) != 15 and len(digits) != 16:
    print("Invalid number")

# Take every 2-nth element of the number into a new list
underlined = digits[::2]

# Multiply each of the underlined digit by 2
product = [i * 2 for i in map(int, underlined)]

# Join all the digits for splitting later
product = int(''.join(map(str, product)))

# Sum those products’ digit
prod_digits = [int(i) for i in str(product)]    # Convert string digits in list to type integer
sum_product = sum(prod_digits)

# Sum of un-multiplied digits from line 7
un_m = sum([int(i) for i in digits[1::2]])      # Convert string digits in sliced list to type integer then sum the integers

# Sum of products' sum and un-multiplied sum
valid = sum_product + un_m
valid = list(str(valid))

# Validating VISA
if (len(digits) == 13 or len(digits) == 16) and valid[1] == "0" and digits[0] == "4":
    print("VISA\n")

# Validating MASTERCARD
elif len(digits) == 16 and valid[1] =="0" and ( digits[:2] == ["5", "1"] or
                                                digits[:2] == ["5", "2"] or
                                                digits[:2] == ["5", "3"] or
                                                digits[:2] == ["5", "4"] or
                                                digits[:2] == ["5", "5"]):
    print("MASTERCARD\n")

# Validating AMEX
elif len(digits) == 15 and (digits[:2] == ["3", "4"] or digits[:2] == ["3", "7"]):
    print("AMEX\n")

else:
    print("INVALID\n")
