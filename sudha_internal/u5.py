import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("input.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

sobelx = cv2.Sobel(gray, cv2.CV_64F, 1, 0)
sobely = cv2.Sobel(gray, cv2.CV_64F, 0, 1)
sobel = cv2.magnitude(sobelx, sobely)

laplacian = cv2.Laplacian(gray, cv2.CV_64F)
canny = cv2.Canny(gray, 100, 200)

plt.subplot(221)
plt.title("Original Image")
plt.imshow(gray, cmap='gray')

plt.subplot(222)
plt.title("Sobel Edge")
plt.imshow(sobel, cmap='gray')

plt.subplot(223)
plt.title("Laplacian Edge")
plt.imshow(laplacian, cmap='gray')

plt.subplot(224)
plt.title("Canny Edge")
plt.imshow(canny, cmap='gray')

plt.show()
