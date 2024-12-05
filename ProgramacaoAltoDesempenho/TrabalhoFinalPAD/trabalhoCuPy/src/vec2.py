from pygame.locals import *
import math
import cupy
cp = cupy


class Vec2:
    def __init__(self, x, y) -> None:
        if (type(x) is Vec2) and (type(y) is Vec2):
            self.x = float(cp.subtract(y.x, x.x))
            self.y = float(cp.subtract(y.y, x.y))
        else:
            self.x: float = float(x)
            self.y: float = float(y)
        
    def __add__(self, v: 'Vec2') -> 'Vec2':
        return Vec2(float(cp.add(self.x, v.x)), float(cp.add(self.y, v.y)))
    
    def __sub__(self, v: 'Vec2') -> 'Vec2':
        return Vec2(float(cp.subtract(self.x, v.x)), float(cp.subtract(self.y, v.y)))
    
    def __mul__(self, v):
        if type(v) is float:
            return Vec2(float(cp.multiply(self.x, v)), float(cp.multiply(self.y, v)))
        elif type(v) is Vec2:
            return float(cp.add(cp.multiply(self.x, v.x), cp.multiply(self.y, v.y)))
        
    def __truediv__(self, v: float) -> 'Vec2':
        if type(v) is float:
            return Vec2(float(cp.divide(self.x, v)), float(cp.divide(self.y, v)))
        elif type(v) is Vec2:
            return float(cp.add(cp.divide(self.x, v.x), cp.divide(self.y, v.y)))

    def module(self) -> float:
        return float(cp.sqrt(cp.add(cp.power(self.x, 2), cp.power(self.y, 2))))
    
    def set_module(self, mod: float) -> None:
        k = float(cp.divide(mod, self.module()))
        self.x = float(cp.multiply(self.x, k))
        self.y = float(cp.multiply(self.y, k))

    def unit(self) -> 'Vec2':
        return Vec2(self.x, self.y) / self.module()
    
    def s_distance_between(v1: 'Vec2', v2: 'Vec2') -> float:
        return Vec2(v1, v2).module()
    
    def s_angle_between(v1: 'Vec2', v2: 'Vec2') -> float:
        if v1.module() <= 0.01 or v2.module() <= 0.01:
            return 0.0
        return math.acos((v1 * v2) / float(cp.multiply(v1.module(), v2.module())))
    
    def vsin(self) -> float:
        return cp.divide(self.y, self.module())
    
    def vcos(self) -> float:
        return cp.divide(self.x, self.module())
    
    def argument(self) -> float:
        vsin = self.vsin()
        vcos = self.vcos()
        if vsin < 0.0:
            return cp.subtract(cp.multiply(2, math.pi), math.acos(vcos))
        elif vsin > 0.0:
            return math.acos(vcos)
        elif vsin == 0.0 and vcos == 1.0:
            return 0.0
        else: # if vsin == 0.0 and v cos = -1.0
            return math.pi
        
    def rotate(self, theta: float) -> None:
        t_sin = math.sin(theta)
        t_cos = math.cos(theta)
        prev_x = self.x
        self.x = float(cp.subtract(cp.multiply(self.x, t_cos), cp.multiply(self.y, t_sin)))
        self.y = float(cp.add(cp.multiply(prev_x, t_sin), cp.multiply(self.y, t_cos)))