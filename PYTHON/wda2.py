import pandas as pd
import matplotlib.pyplot as plt

# ---------------------------------
# LOAD DATA
# ---------------------------------
df = pd.read_csv("/Users/sumitkumar/Downloads/siteanalysis.csv")

# ---------------------------------
# BASIC CLEANING
# ---------------------------------
# change column names if needed
CITY_COL = "city"
TIME_COL = "created_at"
GROUP_COL = "page"     # example: page / event / url / type

# parse datetime
df[TIME_COL] = pd.to_datetime(df[TIME_COL], errors="coerce")

# ---------------------------------
# 1. BAR GRAPH — CITY DISTRIBUTION
# ---------------------------------
if CITY_COL in df.columns:
    city_counts = df[CITY_COL].value_counts().head(10)

    plt.figure(figsize=(10, 5))
    plt.bar(city_counts.index, city_counts.values)
    plt.title("Top Cities")
    plt.xlabel("City")
    plt.ylabel("Count")
    plt.xticks(rotation=30, ha="right")
    plt.tight_layout()
    plt.show()

# ---------------------------------
# 2. TIME SCHEDULING GRAPH (GROUPED)
# ---------------------------------
if TIME_COL in df.columns and GROUP_COL in df.columns:
    # group by date + category
    grouped = (
        df
        .groupby([df[TIME_COL].dt.date, GROUP_COL])
        .size()
        .unstack(fill_value=0)
    )

    plt.figure(figsize=(12, 6))
    for col in grouped.columns:
        plt.plot(grouped.index, grouped[col], label=col)

    plt.title("Activity Over Time (Grouped)")
    plt.xlabel("Date")
    plt.ylabel("Count")
    plt.legend()
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()
