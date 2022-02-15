import numpy

def f(x, m, M, l, g, D_x, D_theta):
    return numpy.array([[0], [4*l/(4*M*l + 3*l*m*numpy.sin(x[2, 0])**2 + l*m)], [0], [-3*l*m*numpy.cos(x[2, 0])/(4*M*l**2*m + 3*l**2*m**2*numpy.sin(x[2, 0])**2 + l**2*m**2)]])