#!/usr/bin/env bash
# Scaffold a new problem's C++, Java, and Python files inside a section folder.
#
# Usage:
#   ./scripts/new-problem.sh <section-folder> "<Problem Name>" <problem-url> <difficulty>
#
# Example:
#   ./scripts/new-problem.sh 01-Arrays "Best Time to Buy and Sell Stock" \
#     https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ Easy

set -euo pipefail

if [ "$#" -ne 4 ]; then
  echo "Usage: $0 <section-folder> \"<Problem Name>\" <url> <difficulty>"
  exit 1
fi

SECTION="$1"
NAME="$2"
URL="$3"
DIFFICULTY="$4"

if [ ! -d "$SECTION" ]; then
  echo "Section folder '$SECTION' not found."
  exit 1
fi

# next index = count of existing cpp files + 1
COUNT=$(find "$SECTION/cpp" -name '*.cpp' | wc -l | tr -d ' ')
IDX=$(printf "%02d" $((COUNT + 1)))

SLUG=$(echo "$NAME" | tr '[:upper:]' '[:lower:]' | sed 's/[^a-z0-9]/-/g' | sed 's/-\+/-/g' | sed 's/^-\|-$//g')
PASCAL=$(echo "$NAME" | sed -r 's/(^|[^a-zA-Z0-9])([a-zA-Z])/\U\2/g' | tr -d ' ' | tr -cd '[:alnum:]')
SNAKE=$(echo "$SLUG" | tr '-' '_')

CPP_FILE="$SECTION/cpp/${IDX}-${SLUG}.cpp"
JAVA_FILE="$SECTION/java/${IDX}-${PASCAL}.java"
PY_FILE="$SECTION/python/${IDX}_${SNAKE}.py"

cat > "$CPP_FILE" << EOF
/*
 * Problem   : $NAME
 * Link      : $URL
 * Difficulty: $DIFFICULTY
 * Approach  :
 * Time      :
 * Space     :
 */

class Solution {
public:
    // TODO: implement
};
EOF

cat > "$JAVA_FILE" << EOF
/*
 * Problem   : $NAME
 * Link      : $URL
 * Difficulty: $DIFFICULTY
 * Approach  :
 * Time      :
 * Space     :
 */

public class $PASCAL {
    // TODO: implement
}
EOF

cat > "$PY_FILE" << EOF
"""
Problem   : $NAME
Link      : $URL
Difficulty: $DIFFICULTY
Approach  :
Time      :
Space     :
"""


class Solution:
    # TODO: implement
    pass
EOF

echo "Created:"
echo "  $CPP_FILE"
echo "  $JAVA_FILE"
echo "  $PY_FILE"
echo ""
echo "Replace the matching placeholder row in $SECTION/README.md with:"
echo "| $IDX | [$NAME]($URL) | $DIFFICULTY | [Solution](./cpp/${IDX}-${SLUG}.cpp) | [Solution](./java/${IDX}-${PASCAL}.java) | [Solution](./python/${IDX}_${SNAKE}.py) |"
