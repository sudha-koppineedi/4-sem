import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread("input.jpg", cv2.IMREAD_GRAYSCALE)

dft = np.fft.fft2(img)
dft_shift = np.fft.fftshift(dft)

rows, cols = img.shape
crow, ccol = rows//2, cols//2

mask = np.zeros((rows, cols), np.uint8)
cv2.circle(mask, (ccol, crow), 50, 1, -1)

filtered = dft_shift * mask

ifft_shift = np.fft.ifftshift(filtered)
img_back = np.fft.ifft2(ifft_shift)
img_back = np.abs(img_back)

plt.subplot(121)
plt.title("Original Image")
plt.imshow(img, cmap='gray')

plt.subplot(122)
plt.title("Filtered Image")
plt.imshow(img_back, cmap='gray')

plt.show()
