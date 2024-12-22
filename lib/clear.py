import os
import shutil

def delete_files_and_folders(root_dir):
    for root, dirs, files in os.walk(root_dir, topdown=False):
        # 仅删除名为.dSYM的文件夹，保留其他文件夹
        for name in list(dirs):
            dir_path = os.path.join(root, name)
            if name.endswith('.dSYM'):
                shutil.rmtree(os.path.join(root, name))
                print(f"Deleted directory: {dir_path}")
        # 删除所有非.cpp文件
        for name in files:
            if not name.endswith('.cpp') :
                if name.endswith('.py') or name.endswith('.json') or name == "README.md":
                    continue
                file_path = os.path.join(root, name)
                os.remove(os.path.join(root, name))
                print(f"Deleted file: {file_path}")

root_dir = './'
dirs = os.listdir( root_dir )
if '.git' in dirs:
    dirs.remove('.git')

for dir in dirs:
    delete_files_and_folders(dir)