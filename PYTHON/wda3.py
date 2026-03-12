import pandas as pd
import matplotlib.pyplot as plt

# -------------------------
# LOAD DATA
# -------------------------
df = pd.read_csv("/Users/sumitkumar/Downloads/siteanalysis.csv")

print("Columns found:")
print(df.columns.tolist())

# -------------------------
# CONFIG (CHANGE THESE)
# -------------------------
CITY_COL = "city"
TIME_COL = "timestamp"      # CHANGE to match your CSV
GROUP_COL = "page"          # CHANGE to match your CSV

# -------------------------
# BAR GRAPH — CITIES
# -------------------------
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
else:
    print(f"Column '{CITY_COL}' not found")

# -------------------------
# TIME SERIES — GROUPED
# -------------------------
if TIME_COL in df.columns and GROUP_COL in df.columns:
    df[TIME_COL] = pd.to_datetime(df[TIME_COL], errors="coerce")

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
else:
    print("Time or group column not found")
