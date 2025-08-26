Week 1 Progress Log

Environment & Containerization
 Built a ROS 2 Humble dev image (Ubuntu 22.04 base).

 Added ROS 2 apt repo via keyring; installed ros-humble-desktop.

 Installed dev tools: build-essential, cmake, git, clang-format, python3-pip/venv, python3-rosdep, python3-colcon-common-extensions.

 Initialized rosdep in the image; auto-source ROS in /etc/bash.bashrc.

 Created non-root dev user (UID/GID alignable).

 Exposed ~/ros2_ws and ~/robotics-portfolio as working dirs (bind-mount targets).

 Confirmed Docker run/exec lifecycle, bind-mounts, logs, prune.

Git & Repo Hygiene

 Set global identity (user.name, user.email).

 Generated SSH key and added to GitHub.

 Initialized two repos:

ros2_ws (workspace; .gitignore with build, install, log, etc.)

robotics-portfolio (notes/demos; basic .gitignore)

 Adopted Conventional Commits; added commit template.

 Installed pre-commit with hooks (trailing whitespace, EOF fixer, YAML check, black, clang-format).

 Configured .clang-format and pyproject.toml for formatter rules.

C++ refresher (pure CMake)

 Wrote minimal main.cpp and CMakeLists.txt.

 Built with cmake -S -B and cmake --build, ran binary.

ROS 2 Workspace

 Created C++ package cpp_pubsub (rclcpp/std_msgs).

 Implemented C++ talker and listener; wired in CMake; installed targets.

 Created Python package py_pubsub (rclpy/std_msgs).

 Implemented Python talker.py and listener.py; added setup.py console scripts.

 Built with colcon build --symlink-install; sourced install/setup.bash.

 Ran talker/listener (C++ and Python) in separate terminals.

 Used ros2 topic list/echo to inspect /chatter.

Quality & Push

 Ran pre-commit run --all-files and formatters.

 Pushed repos to GitHub over SSH.
