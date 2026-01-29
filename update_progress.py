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

# Count .cpp files in each category folder
for label, folder in categories.items():
    path = os.path.join(BASE, folder)
    if os.path.isdir(path):
        counts[label] = sum(
            1 for f in os.listdir(path) if f.endswith(".cpp")
        )
    else:
        counts[label] = 0

total = sum(counts.values())

# Build progress table
table = (
    "| Section | Solved |\n"
    "|--------|--------|\n" +
    "\n".join(f"| {k} | {v} |" for k, v in counts.items()) +
    f"\n| **Total** | **{total}** |"
)

# Read README.md
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# Regex to replace the entire progress table safely
pattern = r"\| Section \| Solved \|\n\|[-| ]+\|\n(?:\|.*\|\n)*"

new_content, replaced = re.subn(
    pattern,
    table + "\n",
    content
)

if replaced == 0:
    raise RuntimeError("❌ Progress table not found in README.md")

# Write updated README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(new_content)

print("✅ CSES progress tracker updated successfully 🚀")
