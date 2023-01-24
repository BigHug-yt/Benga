import os
import subprocess
import CheckPython
import platform

# make sure everything is installed
CheckPython.ValidatePackages()

# Change from Scripts directory to root directory
os.chdir('../')

print("Running premake...")
subprocess.call([os.path.abspath("./scripts/Win-GenProjects.bat"), "nopause"])
