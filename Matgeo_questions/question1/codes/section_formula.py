import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("points.txt", delimiter=',', max_rows=len(list(open("./points.txt")))-1)

# Extract the x and y coordinates
x1 = points[:21, 0]
y1 = points[:21, 1]
x2 = points[20:, 0]
y2 = points[20:, 1]
A = np.array([1, 3]).reshape(-1,1)
P = np.array([-3.5, 0]).reshape(-1,1)
B = np.array([4, 5]).reshape(-1,1)
plt.figure()
plt.plot(x1, y1, label='AB', linestyle='-', color='blue')
plt.plot(x2, y2, label='PA', linestyle='--',color='blue')

tri_coords = np.block([A,P,B])  
plt.scatter(tri_coords[0,:], tri_coords[1, :])
vert_labels = ['A','P','B'];
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    plt.text(tri_coords[0, i], tri_coords[1, i], f'{txt}\n({tri_coords[0, i]:.2f}, {tri_coords[1, i]:.2f})',
    fontsize=12, color = 'black', ha='center', va='bottom')
plt.xlabel("x")
plt.ylabel("y")
plt.title("plot of points A,P,B")
plt.grid(True)
plt.legend()
plt.show()
