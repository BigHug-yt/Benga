import os
import subprocess
import CheckPython
import platform

# make sure everything is installed
CheckPython.ValidatePackages()

from SetupPremake import PremakeConfig as PremakeRequirements

# Change from Scripts directory to root directory
os.chdir('../')

premakeInstalled = PremakeRequirements.Validate()

if (premakeInstalled):
	if platform.system() == "Windows":
		print("\nRunning premake...")
		subprocess.call([os.path.abspath("./scripts/Win-GenProjects.bat"), "nopause"])
	print("\nSetup completed!")
else:
	print("Benga requires Premake to generate project files.")
