import cupy as cp
import numpy as np

a_np = np.arange(10)
s = cp.cuda.Stream()
with s:
    a_cp = cp.asarray(a_np)  # H2D transfer on stream s
    b_cp = cp.sum(a_cp)      # kernel launched on stream s
    assert s == cp.cuda.get_current_stream()