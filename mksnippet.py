import os
import json

folders = ["./combinatoria", "./"]

snippets = {}
for folder in folders:
    for filename in os.listdir(folder):
        if filename.endswith(".cpp"):
            filepath = os.path.join(folder, filename)
            with open(filepath, "r", encoding="utf-8") as f:
                content = f.read()
            
            name_without_ext = os.path.splitext(filename)[0]
            
            snippets[filename] = {
                "prefix": f"__{name_without_ext}",
                "body": content.splitlines(),
                "description": f"Snippet from {filename}"
            }

with open("cpp_snippets.code-snippets", "w", encoding="utf-8") as out:
    json.dump(snippets, out, indent=4)
