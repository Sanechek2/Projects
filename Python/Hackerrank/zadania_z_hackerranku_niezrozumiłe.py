# n = int(input())
#
# students = {}   # имя → список его оценок
# tests = {}      # test_id → список всех оценок по этому тесту
#
# for _ in range(n):
#     parts = input().split()
#     name = parts[0]
#
#     # создаём список оценок для студента
#     students[name] = []
#
#     # обрабатываем пары вида test:score
#     for pair in parts[1:]:
#         test_id, score = pair.split(":")
#         score = float(score)
#
#         # добавляем оценку студенту
#         students[name].append(score)
#
#         # добавляем оценку тесту
#         if test_id not in tests:
#             tests[test_id] = []
#         tests[test_id].append(score)
#
# # --- вывод среднего по студентам ---
# for name in sorted(students.keys()):
#     avg = sum(students[name]) / len(students[name])
#     print(name, avg)
#
# # --- вывод среднего по тестам ---
# for test_id in sorted(tests.keys()):
#     avg = sum(tests[test_id]) / len(tests[test_id])
#     print(test_id, avg)



# def is_pal(s, l, r, removes_left):
#     while l < r:
#         if s[l] == s[r]:
#             l += 1
#             r -= 1
#         else:
#             if removes_left == 0:
#                 return False
#             # пробуем удалить левый или правый символ
#             return (is_pal(s, l + 1, r, removes_left - 1) or
#                     is_pal(s, l, r - 1, removes_left - 1))
#     return True
#
#
# s = input().strip().lower()
#
# if is_pal(s, 0, len(s) - 1, 2):
#     print("ДА")
# else:
#     print("НЕТ")



# n, m = map(int, input().split())
# s = input().strip()
#
# matrix = [input().strip() for _ in range(n)]
#
# # Проверяем строки
# for row in matrix:
#     if s in row or s in row[::-1]:
#         print("YES")
#         exit()
#
# # Проверяем столбцы
# for col in range(m):
#     column = "".join(matrix[row][col] for row in range(n))
#     if s in column or s in column[::-1]:
#         print("YES")
#         exit()
#
# print("NO")


# def area(a, b, c):
#     # Векторное произведение (площадь * 2)
#     cross = abs((b[0] - a[0]) * (c[1] - a[1]) -
#                 (b[1] - a[1]) * (c[0] - a[0]))
#     return cross / 2
#
#
# n = int(input())
# pts = [tuple(map(int, input().split())) for _ in range(n)]
#
# min_area = float('inf')
# max_area = 0.0
#
# # Перебираем все тройки точек
# for i in range(n):
#     for j in range(i + 1, n):
#         for k in range(j + 1, n):
#             A = area(pts[i], pts[j], pts[k])
#             if A > 0:  # не вырожденный треугольник
#                 min_area = min(min_area, A)
#                 max_area = max(max_area, A)
#
# print(min_area, max_area)



# n, m = map(int, input().split())
# a = [list(map(int, input().split())) for _ in range(n)]
#
# max_sum = 0
#
# # --- Диагонали ↘ (вниз-вправо) ---
#
# # стартуем с верхней строки
# for start_col in range(m):
#     i, j = 0, start_col
#     s = 0
#     while 0 <= i < n and 0 <= j < m:
#         s += a[i][j]
#         i += 1
#         j += 1
#     max_sum = max(max_sum, s)
#
# # стартуем с первого столбца (кроме [0][0], уже было)
# for start_row in range(1, n):
#     i, j = start_row, 0
#     s = 0
#     while 0 <= i < n and 0 <= j < m:
#         s += a[i][j]
#         i += 1
#         j += 1
#     max_sum = max(max_sum, s)
#
# # --- Диагонали ↙ (вниз-влево) ---
#
# # стартуем с верхней строки
# for start_col in range(m):
#     i, j = 0, start_col
#     s = 0
#     while 0 <= i < n and 0 <= j < m:
#         s += a[i][j]
#         i += 1
#         j -= 1
#     max_sum = max(max_sum, s)
#
# # стартуем с последнего столбца (кроме [0][m-1], уже было)
# for start_row in range(1, n):
#     i, j = start_row, m - 1
#     s = 0
#     while 0 <= i < n and 0 <= j < m:
#         s += a[i][j]
#         i += 1
#         j -= 1
#     max_sum = max(max_sum, s)
#
# print(max_sum)



# n, q = map(int, input().split())
# s = input().strip()
#
# longest = s  # самая длинная строка, появившаяся в процессе
#
# for _ in range(q):
#     line = input().strip()
#     a_str, b_str, t = line.split(";")
#     a = int(a_str)
#     b = int(b_str)
#
#     L = min(a, b)
#     R = max(a, b)
#
#     # формируем новую строку
#     new_s = s[:L] + t + s[R+1:]
#
#     # обновляем самую длинную строку
#     if len(new_s) > len(longest):
#         longest = new_s
#
#     s = new_s  # обновляем текущую строку
#
# print(s)
# print(longest)



# n = int(input())
#
# wins = {}      # player → number of wins
# points = {}    # player → total points
#
# for _ in range(n):
#     left, right = input().split()
#
#     p1, s1 = left.split(":")
#     p2, s2 = right.split(":")
#     s1 = int(s1)
#     s2 = int(s2)
#
#     # Инициализация игроков
#     if p1 not in wins:
#         wins[p1] = 0
#         points[p1] = 0
#     if p2 not in wins:
#         wins[p2] = 0
#         points[p2] = 0
#
#     # Добавляем очки
#     points[p1] += s1
#     points[p2] += s2
#
#     # Победитель матча
#     if s1 > s2:
#         wins[p1] += 1
#     elif s2 > s1:
#         wins[p2] += 1
#     # если ничья — никто не получает победу
#
# # Сортировка:
# # 1) по победам (убывание)
# # 2) по сумме очков (убывание)
# # 3) по имени (возрастание ASCII)
# players = sorted(wins.keys(), key=lambda p: (-wins[p], -points[p], p))
#
# for p in players:
#     print(p)



# s = input().strip()
# n = len(s)
#
# for k in range(1, n + 1):
#     freq = {}
#     for i in range(n - k + 1):
#         sub = s[i:i+k]
#         freq[sub] = freq.get(sub, 0) + 1
#
#     # выбираем: максимальная частота, при равенстве — минимальная строка
#     best = min(freq.items(), key=lambda x: (-x[1], x[0]))[0]
#     print(best)



# m, n = map(int, input().split())
# matrix = [list(map(int, input().split())) for _ in range(m)]
#
# k = int(input())
# ops = [input().strip() for _ in range(k)]
#
# for op in ops:
#     if op == "T":
#         # Транспонирование
#         matrix = [list(row) for row in zip(*matrix)]
#     else:
#         cmd, idx = op.split()
#         idx = int(idx)
#         if cmd == "RR":
#             # Переворот строки
#             matrix[idx] = matrix[idx][::-1]
#         elif cmd == "RC":
#             # Переворот столбца
#             for i in range(len(matrix) // 2):
#                 matrix[i][idx], matrix[-1 - i][idx] = matrix[-1 - i][idx], matrix[i][idx]
#
# # Вывод результата
# for row in matrix:
#     print(*row)



# n = int(input())
# start_i, start_j = map(int, input().split())
# matrix = [list(map(int, input().split())) for _ in range(n)]
#
# i, j = start_i, start_j
#
# while True:
#     row = matrix[i]
#     min_in_row = min(row)
#     min_j = row.index(min_in_row)
#
#     if j != min_j:
#         j = min_j
#         continue
#
#     # если уже на минимуме строки — ищем минимум в колонке
#     col = [matrix[x][j] for x in range(n)]
#     min_in_col = min(col)
#     min_i = col.index(min_in_col)
#
#     if i != min_i:
#         i = min_i
#         continue
#
#     # если уже на минимуме строки и столбца — остановка
#     break
#
# print(i, j)



# m, n = map(int, input().split())
# matrix = [list(map(int, input().split())) for _ in range(m)]
#
# rows_to_zero = set()
# cols_to_zero = set()
#
# # Находим все строки и столбцы, где есть 0
# for i in range(m):
#     for j in range(n):
#         if matrix[i][j] == 0:
#             rows_to_zero.add(i)
#             cols_to_zero.add(j)
#
# # Обнуляем строки
# for r in rows_to_zero:
#     for j in range(n):
#         matrix[r][j] = 0
#
# # Обнуляем столбцы
# for c in cols_to_zero:
#     for i in range(m):
#         matrix[i][c] = 0
#
# # Вывод результата
# for row in matrix:
#     print(*row)



# n = int(input())
# a = [list(map(int, input().split())) for _ in range(n)]
#
# # направления соседей (8 направлений)
# dirs = [
#     (-1, -1), (-1, 0), (-1, 1),
#     (0, -1),          (0, 1),
#     (1, -1),  (1, 0), (1, 1)
# ]
#
# result = [[0]*n for _ in range(n)]
#
# for i in range(n):
#     for j in range(n):
#         # если сам >= 3 — проходит
#         if a[i][j] >= 3:
#             result[i][j] = 1
#             continue
#
#         # собираем соседей
#         s = 0
#         cnt = 0
#         for di, dj in dirs:
#             ni, nj = i + di, j + dj
#             if 0 <= ni < n and 0 <= nj < n:
#                 s += a[ni][nj]
#                 cnt += 1
#
#         # среднее >= 3?
#         if cnt > 0 and s / cnt >= 3:
#             result[i][j] = 1
#         else:
#             result[i][j] = 0
#
# # вывод
# for row in result:
#     print(*row)



# n, m = map(int, input().split())
# a = []
# for i in range(m):
#     row = list(map(int, input().split()))
#     a.append(row)
#
# for j in range(n):
#     col = [a[i][j] for i in range(m)]
#     col.sort()
#     for i in range(m):
#         a[i][j] = col[i]
#
# for i in range(m):
#     print(' '.join(map(str, a[i])))



