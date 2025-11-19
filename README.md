3D Hand Tracking and Robotic Actuation System using MediaPipe and Arduino

This project implements a real-time 3D hand tracking system using dual cameras, MediaPipe, and stereo triangulation, integrated with an Arduino-controlled robotic hand. The system detects hand landmarks, computes joint angles, applies calibration, and actuates servos to mirror finger movement accurately and safely.


🚀 Overview

The system captures synchronized frames from two USB webcams, detects hand landmarks using MediaPipe, and performs DLT triangulation to obtain 3D positions. A custom angle estimation pipeline converts these positions into meaningful joint angles for five fingers and the wrist. The output angles are mapped to servo constraints and transmitted via serial communication to an Arduino, controlling a robotic hand in real time.

This project is designed for use in robotics, human–computer interaction, and gesture-based control systems.

✨ Key Features

Dual-camera 3D hand tracking

MediaPipe Hands (0.10.21)

Stereo triangulation using DLT

Joint angle computation for all five fingers + wrist

Two calibration modes

Dynamic palm calibration

User-guided calibration

Servo constraint mapping with mechanical safety limits

Arduino integration using a clean serial protocol

Virtual hand & 3D landmark visualization
