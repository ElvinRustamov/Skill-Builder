# Transforming 3D Coordinates Between Frames Using Krylov Angles

This repository contains an academic report that explains how to convert a point from one 3D coordinate system to another using **Krylov (Euler–Krylov) angles** and rotation matrices.

The material is written at an **undergraduate engineering / computer science level**, assuming only basic linear algebra knowledge, and is suitable for coursework, self-study, or reference in robotics, computer graphics, and simulation contexts.

**Main document:**  
- [`Converting_one_coordinate_to_another_in_3D.pdf`](Converting_one_coordinate_to_another_in_3D.pdf) :contentReference[oaicite:0]{index=0}

---

## Overview

In real-world systems, the same physical point can be represented in multiple coordinate frames, such as:
- a **world frame**
- a **robot or body frame**
- a **sensor or camera frame**

To use measurements consistently, coordinates must be **transformed between frames**.  
This report focuses on **pure rotational transformations** (shared origin) using a **three-angle rotation sequence** known as Krylov (Euler–Krylov) angles.

---

## Topics Covered

The report develops the subject from first principles and includes:

- What a **3D coordinate system** is  
- Why **coordinate transformations** are necessary  
- The **right-hand rule** and rotation conventions  
- What **Krylov (Euler–Krylov) angles** are and how they differ from single-axis rotations  
- **Extrinsic vs. intrinsic** rotation interpretation  
- Derivation of rotation matrices about:
  - the **x-axis**
  - the **y-axis**
  - the **z-axis**
- Construction of a **composite rotation matrix**
- A **fully worked numerical example** with:
  - initial coordinates
  - chosen angles
  - intermediate vectors
  - final transformed coordinates
- LaTeX-ready descriptions for **3D axis and rotation figures**
- Discussion of **order dependence**, conventions, and limitations (gimbal lock)

---

## Mathematical Convention Used

The report uses the following rotation sequence:

\[
R(\psi, \theta, \phi) = R_z(\psi)\, R_y(\theta)\, R_x(\phi)
\]

Where:
- \(\phi\) — rotation about the **x-axis**
- \(\theta\) — rotation about the **y-axis**
- \(\psi\) — rotation about the **z-axis**

This is interpreted as:
- **Extrinsic rotations** about fixed axes, or equivalently
- **Intrinsic rotations** about moving axes in reverse order

The convention is stated explicitly to avoid ambiguity.

