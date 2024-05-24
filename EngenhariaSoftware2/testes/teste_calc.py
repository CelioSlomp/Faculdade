import unittest
from calculadora import Calculadora

class TestaCalculadoraPosPos(unittest.TestCase):
    def setUp(self) -> None:
        self.valores = [5, 2]
        self.calc = Calculadora()

    def teste_adicao(self):
        self.assertEqual(self.calc.adicao(self.valores), 7)

    def teste_subtracao(self):
        self.assertEqual(self.calc.subtracao(self.valores), 3)

    def teste_multiplicacao(self):
        self.assertEqual(self.calc.multiplicacao(self.valores), 10)

    def teste_divisao(self):
        self.assertEqual(self.calc.divisao(self.valores), 2.5)

    def teste_exponenciacao(self):
        self.assertEqual(self.calc.exponenciacao(self.valores), 25)

    def teste_raizQuadrada(self):
        self.assertEqual(self.calc.raizQuadrada(self.valores[0]), 2.23606797749979)

class TestaCalculadoraPosNeg(unittest.TestCase):
    def setUp(self) -> None:
        self.valores = [5, -2]
        self.calc = Calculadora()

    def teste_adicao(self):
        self.assertEqual(self.calc.adicao(self.valores), 3)

    def teste_subtracao(self):
        self.assertEqual(self.calc.subtracao(self.valores), 7)

    def teste_multiplicacao(self):
        self.assertEqual(self.calc.multiplicacao(self.valores), -10)

    def teste_divisao(self):
        self.assertEqual(self.calc.divisao(self.valores), -2.5)

    def teste_exponenciacao(self):
        self.assertEqual(self.calc.exponenciacao(self.valores), 0.04)

    def teste_raizQuadrada(self):
        self.assertEqual(self.calc.raizQuadrada(self.valores[0]), 2.23606797749979)

class TestaCalculadoraNegNeg(unittest.TestCase):
    def setUp(self) -> None:
        self.valores = [-5, -2]
        self.calc = Calculadora()

    def teste_adicao(self):
        self.assertEqual(self.calc.adicao(self.valores), -7)

    def teste_subtracao(self):
        self.assertEqual(self.calc.subtracao(self.valores), -3)

    def teste_multiplicacao(self):
        self.assertEqual(self.calc.multiplicacao(self.valores), 10)

    def teste_divisao(self):
        self.assertEqual(self.calc.divisao(self.valores), 2.5)

    def teste_exponenciacao(self):
        self.assertEqual(self.calc.exponenciacao(self.valores), 0.04)

    def teste_raizQuadrada(self):
        with self.assertRaises(ValueError):
            self.calc.raizQuadrada(self.valores[0])

class TestaCalculadoraValoresInvalidos(unittest.TestCase):
    def setUp(self) -> None:
        self.valores = [None, 2]
        self.calc = Calculadora()

    def teste_adicao(self):
        with self.assertRaises(TypeError):
            self.calc.adicao(self.valores)

    def teste_subtracao(self):
        with self.assertRaises(TypeError):
            self.calc.subtracao(self.valores)

    def teste_multiplicacao(self):
        with self.assertRaises(TypeError):
            self.calc.multiplicacao(self.valores)

    def teste_divisao(self):
        with self.assertRaises(ZeroDivisionError):
            self.calc.divisao([5, 0])

    def teste_exponenciacao(self):
        with self.assertRaises(TypeError):
            self.calc.exponenciacao(self.valores)
        with self.assertRaises(ValueError):
            self.calc.exponenciacao([-5, 1/3])

    def teste_raizQuadrada(self):
        with self.assertRaises(TypeError):
            self.calc.raizQuadrada(self.valores[0])


if __name__ == "__main__":
    unittest.main()