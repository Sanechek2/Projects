n = int(input())

students = {}   # имя → список его оценок
tests = {}      # test_id → список всех оценок по этому тесту

for _ in range(n):
    parts = input().split()
    name = parts[0]

    # создаём список оценок для студента
    students[name] = []

    # обрабатываем пары вида test:score
    for pair in parts[1:]:
        test_id, score = pair.split(":")
        score = float(score)

        # добавляем оценку студенту
        students[name].append(score)

        # добавляем оценку тесту
        if test_id not in tests:
            tests[test_id] = []
        tests[test_id].append(score)

# --- вывод среднего по студентам ---
for name in sorted(students.keys()):
    avg = sum(students[name]) / len(students[name])
    print(name, avg)

# --- вывод среднего по тестам ---
for test_id in sorted(tests.keys()):
    avg = sum(tests[test_id]) / len(tests[test_id])
    print(test_id, avg)