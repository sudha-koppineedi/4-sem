import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("input.jpg", 0)

blur = cv2.GaussianBlur(img, (5,5), 0)

kernel = np.array([[0,-1,0],[-1,5,-1],[0,-1,0]])

deblur = cv2.filter2D(blur, -1, kernel)

plt.subplot(121)
plt.title("Blurred Image")
plt.imshow(blur, cmap='gray')

plt.subplot(122)
plt.title("Deblurred Image")
plt.imshow(deblur, cmap='gray')

plt.show()




