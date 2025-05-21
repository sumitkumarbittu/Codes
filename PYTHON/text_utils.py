# text_utils.py

def count_vowels(text):
    """Count the number of vowels in the given string."""
    vowels = "aeiouAEIOU"
    count = sum(1 for char in text if char in vowels)
    return count

def reverse_string(text):
    """Reverse the given string."""
    return text[::-1]

def is_palindrome(text):
    """Check if the given string is a palindrome."""
    # Removing spaces and converting to lowercase for comparison
    cleaned_text = ''.join(text.split()).lower()
    return cleaned_text == reverse_string(cleaned_text)
