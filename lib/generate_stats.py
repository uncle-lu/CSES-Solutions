#!/usr/bin/env python3

import os
import re

# 读取problems_by_category.txt文件
with open(os.path.join(os.path.dirname(__file__), '..', 'problems_by_category.txt'), 'r') as f:
    content = f.read()

# 获取code目录中的文件列表
code_files = os.listdir(os.path.join(os.path.dirname(__file__), '..', 'code'))
code_numbers = set()
for file in code_files:
    if file.endswith('.cpp'):
        number = file[:-4]  # 移除.cpp后缀
        code_numbers.add(number)

# 按类别解析problems_by_category.txt
categories = content.split('\n\n')

total_solved = 0
total_problems = 0

print("| 题目类型                      |  解决数量  |")
print("| ----------------------------- | :--------: |")

# 处理每个类别
for category in categories:
    if not category.strip():
        continue
        
    lines = category.split('\n')
    category_name = lines[0].replace(':', '')
    
    # 统计该类别中的题目总数
    problem_count = 0
    solved_count = 0
    
    for line in lines[1:]:  # 跳过类别标题行
        if ':' in line and not line.startswith('-'):
            problem_count += 1
            number = line.split(':')[0].strip()
            if number in code_numbers:
                solved_count += 1
    
    # 格式化类别名称，使其与README.md中的一致
    display_name = category_name
    print(f"| {display_name:<29} |   {solved_count:>2}/{problem_count:>2}    |")
    total_solved += solved_count
    total_problems += problem_count

print(f"| {'*Total*':<29} | *{total_solved:>2}/{total_problems:>3}*  |")