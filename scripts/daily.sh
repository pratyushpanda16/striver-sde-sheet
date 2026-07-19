#!/usr/bin/env bash
# Scaffold a solved problem, log it in DAILY_LOG.md, and commit — all in one go.
# Meant to be run once per day so every solving session becomes a real commit.
#
# Usage:
#   ./scripts/daily.sh <section-folder> "<Problem Name>" <problem-url> <difficulty>
#
# Example:
#   ./scripts/daily.sh 01-Arrays "Best Time to Buy and Sell Stock" \
#     https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ Easy
#
# What it does:
#   1. Calls scripts/new-problem.sh to create the cpp/java/python files
#   2. Appends a row to DAILY_LOG.md with today's date and a running Day number
#   3. Prints the README row to paste into the section's README.md
#   4. Stages everything and creates a commit (does NOT push — review first)

set -euo pipefail

if [ "$#" -ne 4 ]; then
  echo "Usage: $0 <section-folder> \"<Problem Name>\" <url> <difficulty>"
  exit 1
fi

SECTION="$1"
NAME="$2"
URL="$3"
DIFFICULTY="$4"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$REPO_ROOT"

# 1. Scaffold the solution files (reuse new-problem.sh, capture its output)
SCAFFOLD_OUTPUT=$("$SCRIPT_DIR/new-problem.sh" "$SECTION" "$NAME" "$URL" "$DIFFICULTY")
echo "$SCAFFOLD_OUTPUT"

# 2. Work out the next Day number from DAILY_LOG.md (count existing data rows)
DAY_COUNT=$(grep -cE '^\| [0-9]+ \|' DAILY_LOG.md || true)
DAY_NUM=$((DAY_COUNT + 1))
TODAY=$(date +%F)

# 3. Append to DAILY_LOG.md
echo "| $DAY_NUM | $TODAY | [$NAME]($URL) | [$SECTION](./$SECTION) | C++, Java, Python | |" >> DAILY_LOG.md

echo ""
echo "Logged as Day $DAY_NUM in DAILY_LOG.md."
echo ""
echo "Don't forget to paste the row above into $SECTION/README.md, replacing its placeholder."
echo ""

# 4. Stage and commit
read -rp "Fill in the code, then press Enter to stage + commit (Ctrl+C to skip)... "

git add "$SECTION" DAILY_LOG.md
git commit -m "Day $DAY_NUM: $NAME ($SECTION)"

echo "Committed. Run 'git push' when ready."
