import os
import re

BASE = "./"

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

for label, folder in categories.items():
    path = os.path.join(BASE, folder)
    if os.path.isdir(path):
        counts[label] = sum(1 for f in os.listdir(path) if f.endswith(".cpp"))
    else:
        counts[label] = 0

total = sum(counts.values())

table = (
    "| Section | Solved |\n"
    "|--------|--------|\n"
    + "\n".join(f"| {k} | {v} |" for k, v in counts.items())
    + f"\n| **Total** | **{total}** |"
)

with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# ✅ CRLF + LF safe regex
pattern = re.compile(
    r"\| Section \| Solved \|\r?\n"
    r"\|[-| ]+\|\r?\n"
    r"(?:\|.*\|\r?\n)*",
    re.MULTILINE
)

new_content, replaced = pattern.subn(table + "\n", content)

if replaced == 0:
    raise RuntimeError("❌ Progress table not found in README.md")

with open("README.md", "w", encoding="utf-8") as f:
    f.write(new_content)

print("✅ CSES progress tracker updated successfully 🚀")
