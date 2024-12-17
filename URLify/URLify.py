"""
    Write a method to replace all spaces in a string with `%20`. You may assume that the string has sufficient space at
    the end to hold the additional characters, and that you are given the "true" length of thr string.

    Example
    Input: "Mr John Smith       ", 13
    Output: "Mr%20John%20Smith"
"""


def URLify(input_str):
    """
    Replace all spaces in a string with `%20`.

    Parameters
    ----------
    input_str : str
        String to URLify.
    """
    result = input_str.strip()
    result = result.replace(' ', '%20')

    return result


print(URLify("Mr John Smith       "))
# "Mr%20John%20Smith"
