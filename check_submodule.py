#!/usr/bin/env python3
import subprocess
import os

def check_submodule_status():
    print("Checking submodule status...")
    
    # Vérifier le repository principal
    main_status = subprocess.run(['git', 'status', '--porcelain'], 
                                capture_output=True, text=True).stdout
    if main_status:
        print("⚠️  Main repository has uncommitted changes")
    
    # Vérifier le sous-module
    os.chdir('src/common')
    sub_status = subprocess.run(['git', 'status', '--porcelain'], 
                               capture_output=True, text=True).stdout
    if sub_status:
        print("⚠️  Submodule has uncommitted changes")
    
    # Vérifier si le sous-module est à jour
    subprocess.run(['git', 'fetch'])
    sub_behind = subprocess.run(['git', 'status', '-uno'], 
                               capture_output=True, text=True).stdout
    if 'Your branch is behind' in sub_behind:
        print("⚠️  Submodule needs to be pulled")
    
    os.chdir('../..')
    print("✅ Check complete")

if __name__ == "__main__":
    check_submodule_status()
