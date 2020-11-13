import numpy as np

def pagerank(matrix, num_iterations, damping_factor):
	dim = matrix.shape[1]
	rank_vector = np.random.rand(dim,1)
	rank_vector = rank_vector / np.linalg.norm(rank_vector,1)
	matrix_hat = (damping_factor*matrix + (1 - damping_factor)/dim)

	for i in range(num_iterations):
		rank_vector = matrix_hat @ rank_vector

	return rank_vector

def main():
	matrix = np.array([[0,0,0,0,1],[0.5,0,0,0,0],[0,1,0.5,0,0],[0,0,0.5,1,0],[0.5,0,0,0,0]])
	v = pagerank(matrix, 100, 0.85)
	print("Page rank vector\n", v)


if __name__ == '__main__':
	main()
