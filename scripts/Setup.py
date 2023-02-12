import os
import subprocess
import platform

from SetupPython import PythonConfig as PythonRequirements

# make sure everything we need for the setup is installed
PythonRequirements.Validate()

from SetupPremake import PremakeConfig as PremakeRequirements
from SetupVulkan import VulkanConfig as VulkanRequirements

# Change from Scripts directory to root directory
os.chdir('../')

premakeInstalled = PremakeRequirements.Validate()
VulkanRequirements.Validate()

if (premakeInstalled):
	if platform.system() == "Windows":
		print("\nRunning premake...")
		subprocess.call([os.path.abspath("./scripts/Win-GenProjects.bat"), "nopause"])
	print("\nSetup completed!")
else:
	print("Benga requires Premake to generate project files.")
