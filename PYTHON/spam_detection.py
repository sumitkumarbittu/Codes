import string
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem import PorterStemmer

def preprocess_text(text):
    # Lowercasing
    text = text.lower()
    # Removing punctuation
    text = text.translate(str.maketrans('', '', string.punctuation))
    # Tokenizing
    words = word_tokenize(text)
    # Removing stop words
    stop_words = set(stopwords.wordsa('english'))
    words = [word for word in words if word not in stop_words]
    # Stemming
    ps = PorterStemmer()
    words = [ps.stem(word) for word in words]
    return ' '.join(words)


from sklearn.feature_extraction.text import TfidfVectorizer

# Example corpus
messages = ["Congratulations! You've won!", "Are we meeting today?"]

# Vectorize the text using TF-IDF
vectorizer = TfidfVectorizer(preprocessor=preprocess_text)
X = vectorizer.fit_transform(messages)


from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, labels, test_size=0.3, random_state=42)


from sklearn.naive_bayes import MultinomialNB

# Create a model and fit it
model = MultinomialNB()
model.fit(X_train, y_train)


from sklearn.metrics import accuracy_score, classification_report

# Make predictions
y_pred = model.predict(X_test)

# Evaluate accuracy
print("Accuracy:", accuracy_score(y_test, y_pred))

# Classification report (precision, recall, F1-score)
print(classification_report(y_test, y_pred))


import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, classification_report

# Load dataset (Assuming it's a CSV with 'text' and 'label' columns)
data = pd.read_csv('spam.csv')

# Preprocess the text data (Apply your preprocess function here)
data['text'] = data['text'].apply(preprocess_text)

# Split into features (X) and labels (y)
X = data['text']
y = data['label']

# Vectorize the text data using TF-IDF
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(X)

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train a Naive Bayes model
model = MultinomialNB()
model.fit(X_train, y_train)

# Make predictions
y_pred = model.predict(X_test)

# Evaluate the model
print("Accuracy:", accuracy_score(y_test, y_pred))
print(classification_report(y_test, y_pred))
