import os
import json
import sys
import fnmatch
import pathlib

def load_gitignore(folder_path):
    gitignore_path = os.path.join(folder_path, ".gitignore")
    patterns = []
    
    if os.path.isfile(gitignore_path):
        with open(gitignore_path, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith('#'):
                    patterns.append(line)
    
    return patterns

def should_ignore(path, gitignore_patterns):
    if os.path.basename(path).startswith('.'):
        return True
        
    for pattern in gitignore_patterns:
        if fnmatch.fnmatch(path, pattern):
            return True
    
    return False

def process_folder(folder_path, result_snippets=None, path_prefix="", gitignore_patterns=None):
    if result_snippets is None:
        result_snippets = {}
    
    if gitignore_patterns is None:
        gitignore_patterns = load_gitignore(folder_path)
    
    for item in os.listdir(folder_path):
        item_path = os.path.join(folder_path, item)
        rel_path = os.path.join(path_prefix, item)
        
        if should_ignore(item_path, gitignore_patterns) or item.startswith('practice'):
            continue
            
        if os.path.isfile(item_path) and item.endswith(".cpp"):
            with open(item_path, "r", encoding="utf-8") as f:
                content = f.read()
            
            name_without_ext = os.path.splitext(item)[0]
            
            result_snippets[f"{path_prefix}{item}"] = {
                "prefix": f"__{name_without_ext}",
                "body": content.splitlines(),
                "description": f"Snippet from {path_prefix}{item}"
            }
        
        elif os.path.isdir(item_path):
            new_path_prefix = f"{path_prefix}{os.path.basename(item_path)}/"
            sub_gitignore = load_gitignore(item_path)
            all_patterns = gitignore_patterns + sub_gitignore
            process_folder(item_path, result_snippets, new_path_prefix, all_patterns)
    
    return result_snippets

if __name__ == "__main__":
    target_folder = sys.argv[1] if len(sys.argv) > 1 else "."
    all_snippets = process_folder(target_folder)
    
    output_file = f"{os.path.basename(os.path.abspath(target_folder))}_snippets.code-snippets"
    with open(output_file, "w", encoding="utf-8") as out:
        json.dump(all_snippets, out, indent=4)
    
    print(f"Se creo el snipet {output_file} con {len(all_snippets)} elementos")
