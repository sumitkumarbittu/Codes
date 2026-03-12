import pandas as pd
import matplotlib.pyplot as plt

# -------------------------
# LOAD DATA
# -------------------------
df = pd.read_csv("/Users/sumitkumar/Downloads/siteanalysis.csv")   # change file name if needed

# -------------------------
# BASIC INFO
# -------------------------
print(df.info())
print(df.describe())

# -------------------------
# BAR PLOT (NUMERIC AVERAGES)
# -------------------------
df.mean(numeric_only=True).plot(
    kind="bar",
    figsize=(10, 5),
    title="Average of Numeric Columns"
)
plt.tight_layout()
plt.show()

# -------------------------
# TIME SERIES (if exists)
# -------------------------
if "created_at" in df.columns:
    df["created_at"] = pd.to_datetime(df["created_at"], errors="coerce")
    df.groupby(df["created_at"].dt.date).size().plot(
        figsize=(10, 5),
        title="Records Over Time"
    )
    plt.xlabel("Date")
    plt.ylabel("Count")
    plt.tight_layout()
    plt.show()

# -------------------------
# CATEGORICAL FREQUENCY
# -------------------------
if "city" in df.columns:
    df["city"].value_counts().head(10).plot(
        kind="bar",
        figsize=(8, 4),
        title="Top 10 Cities"
    )
    plt.tight_layout()
    plt.show()

# -------------------------
# HISTOGRAM (FIRST NUMERIC COLUMN)
# -------------------------
num_cols = df.select_dtypes(include="number").columns
if len(num_cols) > 0:
    df[num_cols[0]].plot(
        kind="hist",
        bins=30,
        title=f"Distribution of {num_cols[0]}"
    )
    plt.show()
