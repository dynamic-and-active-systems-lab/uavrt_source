# pulse_start_time_sec = data[:, 2]
# pulse_start_time_nanosec = data[:, 3]

# snr = data[:, 10]

# antenna_pose_position_x = data[:, 16]
# antenna_pose_position_y = data[:, 17]
# antenna_pose_position_z = data[:, 18]

# antenna_pose_orientation_x = data[:, 18]
# antenna_pose_orientation_y = data[:, 19]
# antenna_pose_orientation_z = data[:, 20]
# antenna_pose_orientation_w = data[:, 21]

# pulse_pose_log.txt

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
from math import atan2, asin, degrees
from scipy.spatial.transform import Rotation

# Load the data from the text file
data = np.loadtxt("pulse_pose_log.txt", delimiter=",")

# Extract the relevant columns from the data
time = data[:, 2]
snr = data[:, 10]
x = data[:, 16]
y = data[:, 17]
qx = data[:, 19]
qy = data[:, 20]
qz = data[:, 21]
qw = data[:, 22]

# quaternion = data[:, 18:22]

# Convert the quaternion data to Euler angles (yaw, pitch, roll)
# https://stackoverflow.com/questions/56207448/efficient-quaternions-to-euler-transformation
# https://automaticaddison.com/how-to-convert-a-quaternion-into-euler-angles-in-python/
yaw = []
pitch = []
roll = []
for i in range(len(qx)):
    t0 = +2.0 * (qw[i] * qx[i] + qy[i] * qz[i])
    t1 = +1.0 - 2.0 * (qx[i] * qx[i] + qy[i] * qy[i])
    roll.append(degrees(atan2(t0, t1)))

    t2 = +2.0 * (qw[i] * qy[i] - qz[i] * qx[i])
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch.append(degrees(asin(t2)))

    t3 = +2.0 * (qw[i] * qz[i] + qx[i] * qy[i])
    t4 = +1.0 - 2.0 * (qy[i] * qy[i] + qz[i] * qz[i])
    yaw.append(degrees(atan2(t3, t4)))

# Convert quaternion data to Euler angles
# https://docs.scipy.org/doc/scipy/reference/generated/scipy.spatial.transform.Rotation.html
# r = Rotation.from_quat(quaternion)
# euler = r.as_euler('xyz', degrees=True)

# plt.scatter(euler[:,2], snr)
# plt.xlabel('Roll Angle (degrees)')
# plt.ylabel('SNR values')
# plt.show()

# Create a 2D plot of yaw angle vs SNR values
# plt.scatter(yaw, snr)
# plt.title('Yaw Angle (degrees) vs. SNR Values')
# plt.xlabel('Yaw Angle (degrees)')
# plt.ylabel('SNR Values')
# # This will add a red line at x = 351 on the x-axis of the 3D plot.
# plt.axvline(x=-9, color='r')
# plt.show()

# Create a 3D plot of angle vs SNR values with time values for the z-axis
# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# ax.scatter(yaw, snr, time)
# ax.set_xlabel('Yaw Angle (degrees)')
# ax.set_ylabel('SNR values')
# ax.set_zlabel('Time')
# plt.show()

# Create a 2D plot of yaw angle vs SNR values
plt.scatter(yaw, time)
plt.title('Time (s) vs. Yaw Angle (degrees)')
plt.xlabel('Yaw Angle (degrees)')
plt.ylabel('Time (s)')
plt.axvline(x=-9, color='r')
plt.show()