import os
import re

BASE = "./"

# CSES categories mapped to folder names
categories = {
    "Introductory Problems": "IntroductoryProblems",
    "Sorting and Searching": "SortingAndSearching",
    "Dynamic Programming": "DynamicProgramming",
    "Graph Algorithms": "GraphAlgorithms",
    "Range Queries": "RangeQueries",
    "Tree Algorithms": "TreeAlgorithms",
    "Mathematics": "Mathematics",
    "String Algorithms": "StringAlgorithms",
    "Advanced Techniques": "AdvancedTechniques"
}

counts = {}

# Count .cpp files in each category
for label, folder in categories.items():
    path = os.path.join(BASE, folder)
    if os.path.exists(path):
        counts[label] = len(
            [f for f in os.listdir(path) if f.endswith(".cpp")]
        )
    else:
        counts[label] = 0

total = sum(counts.values())

# Read README.md
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# Build progress table
table = (
    "| Section | Solved |\n"
    "|---------|--------|\n" +
    "\n".join([f"| {k} | {v} |" for k, v in counts.items()]) +
    f"\n| **Total** | **{total}** |"
)

# Replace existing progress tracker table
content = re.sub(
    r"\| Section \| Solved \|[\s\S]*?\| \*\*Total\*\* \| \*\*\d+\*\* \|",
    table,
    content
)

# Write updated README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(content)

print("CSES progress tracker updated 🚀")
