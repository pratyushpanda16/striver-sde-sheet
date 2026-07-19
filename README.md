![GitHub Streak](https://streak-stats.demolab.com?user=pratyushpanda16&theme=dark)

# Striver's SDE Sheet — Solutions

My solutions to [Striver's SDE Sheet](https://takeuforward.org/dsa/strivers-sde-sheet-top-coding-interview-problems) — 191 curated interview problems (25 Easy / 93 Medium / 73 Hard) — implemented in **C++**, **Java**, and **Python**.

## 📁 Repo Structure

Solutions are organized **by section**, matching the sheet's own topic grouping exactly. Each section has a language subfolder for C++, Java, and Python.

```
striver-sde-sheet/
├── 01-Arrays/
│   ├── README.md          # problem list + links for this section
│   ├── cpp/
│   ├── java/
│   └── python/
├── 02-Arrays-Part-II/
│   ├── README.md
│   ├── cpp/
│   ├── java/
│   └── python/
├── ...
└── 27-Trie/
```

## 📚 Sections (191 problems total)

| # | Section | Problems | Progress |
|---|---------|----------|----------|
| 01 | [Arrays](./01-Arrays) | 6 | 🟩⬜⬜⬜⬜⬜ 1/6 |
| 02 | [Arrays Part-II](./02-Arrays-Part-II) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 03 | [Arrays Part-III](./03-Arrays-Part-III) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 04 | [Arrays Part-IV](./04-Arrays-Part-IV) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 05 | [Linked List](./05-Linked-List) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 06 | [Linked List Part-II](./06-Linked-List-Part-II) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 07 | [Linked List and Arrays](./07-Linked-List-and-Arrays) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 08 | [Greedy Algorithm](./08-Greedy-Algorithm) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 09 | [Recursion](./09-Recursion) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 10 | [Recursion and Backtracking](./10-Recursion-and-Backtracking) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 11 | [Binary Search](./11-Binary-Search) | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜ 0/8 |
| 12 | [Heaps](./12-Heaps) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 13 | [Stack and Queue](./13-Stack-and-Queue) | 7 | ⬜⬜⬜⬜⬜⬜⬜ 0/7 |
| 14 | [Stack and Queue Part-II](./14-Stack-and-Queue-Part-II) | 10 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0/10 |
| 15 | [String](./15-String) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 16 | [String Part-II](./16-String-Part-II) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 17 | [Binary Tree](./17-Binary-Tree) | 12 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0/12 |
| 18 | [Binary Tree Part-II](./18-Binary-Tree-Part-II) | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜ 0/8 |
| 19 | [Binary Tree Part-III](./19-Binary-Tree-Part-III) | 7 | ⬜⬜⬜⬜⬜⬜⬜ 0/7 |
| 20 | [Binary Search Tree](./20-Binary-Search-Tree) | 7 | ⬜⬜⬜⬜⬜⬜⬜ 0/7 |
| 21 | [Binary Search Tree Part-II](./21-Binary-Search-Tree-Part-II) | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜ 0/8 |
| 22 | [Binary Trees \[Miscellaneous\]](./22-Binary-Trees-Miscellaneous) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 23 | [Graph](./23-Graph) | 12 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0/12 |
| 24 | [Graph Part-II](./24-Graph-Part-II) | 6 | ⬜⬜⬜⬜⬜⬜ 0/6 |
| 25 | [Dynamic Programming](./25-Dynamic-Programming) | 7 | ⬜⬜⬜⬜⬜⬜⬜ 0/7 |
| 26 | [Dynamic Programming Part-II](./26-Dynamic-Programming-Part-II) | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜ 0/8 |
| 27 | [Trie](./27-Trie) | 7 | ⬜⬜⬜⬜⬜⬜⬜ 0/7 |

> Section names, order, and problem counts are pulled directly from the live sheet. Individual
> problem names/links aren't pre-filled here (the sheet renders them via JS), so add each one's
> name, link, and difficulty to the section's README as you solve it — the row placeholders are
> already there, just replace the `_(add problem name...)_` text.

## 🔥 Daily Contribution Workflow

This repo is set up so solving one problem a day gives you a real, meaningful commit —
good for the sheet *and* for keeping your GitHub contribution graph green.

1. Pick the next problem from [the sheet](https://takeuforward.org/dsa/strivers-sde-sheet-top-coding-interview-problems).
2. Run the daily script:
   ```bash
   ./scripts/daily.sh 01-Arrays "Best Time to Buy and Sell Stock" \
     https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ Easy
   ```
   This scaffolds the `.cpp` / `.java` / `.py` files, adds a row to [`DAILY_LOG.md`](./DAILY_LOG.md)
   with today's date, and pauses so you can fill in the actual solution.
3. Write your solution in the three generated files.
4. Paste the printed row into the section's `README.md` (replacing its placeholder row).
5. Press Enter — the script stages and commits everything with a `Day N: ...` message.
6. `git push` when you're ready. Do this once a day and every day shows up on your profile.

**Notes on contribution graphs:**
- GitHub only counts commits made to the **default branch** of a repo you own (or a fork whose
  commits are merged upstream), and only if the repo is **public** — or, for private repos, if
  you've enabled *"Include private contributions"* in your profile settings.
- Commit **something real** each time (actual code), not empty commits — GitHub's spam
  detection and your own repo history will both thank you.
- If you fall behind, resist backdating commits to fake a streak — it's easy to spot and
  defeats the point of tracking real practice.

## 🏆 Streak Stats (optional)

Add this to the top of your README once the repo is live to show a live streak badge
(replace `YOUR_GITHUB_USERNAME`):

```markdown
![GitHub Streak](https://streak-stats.demolab.com?user=YOUR_GITHUB_USERNAME&theme=dark)
```


## 🧭 Naming Convention

| Language | Pattern | Example |
|----------|---------|---------|
| C++ | `NN-problem-name.cpp` | `01-two-sum.cpp` |
| Java | `NN-ProblemName.java` (class name = file name) | `01-TwoSum.java` |
| Python | `NN_problem_name.py` | `01_two_sum.py` |

`NN` is a two-digit index within that section folder, kept in sync across all three languages so problem 1 in C++ maps to problem 1 in Java and Python. `01-Arrays/` has a worked example (Two Sum) in all three languages showing the format.

## ➕ Adding a New Solution

Recommended: use `./scripts/daily.sh` (see workflow above) — it does all of this for you.

Manual steps, if you'd rather:
1. Drop your file into `<section>/<language>/` following the naming convention above.
2. Replace the matching placeholder row in that section's `README.md` with the real problem name, link, and difficulty.
3. Add a row to [`DAILY_LOG.md`](./DAILY_LOG.md).
4. Update the progress checklist in this file.

The scaffold-only script (no logging/commit) is still available:

```bash
./scripts/new-problem.sh 01-Arrays "Best Time to Buy and Sell Stock" https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ Easy
```

## 🛠 Tech

- **C++17**, compiled/tested with `g++`
- **Java 17**
- **Python 3.10+**

## 🔗 Source

[Striver's SDE Sheet — takeUforward](https://takeuforward.org/dsa/strivers-sde-sheet-top-coding-interview-problems)

## 📄 License

MIT — see [LICENSE](./LICENSE).
