import yfinance as yf
import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
from datetime import datetime
import warnings

warnings.filterwarnings("ignore", category=UserWarning)

acoesSilva = ["RAIZ4.SA", "ITSA4.SA", "EMBR3.SA", "LWSA3.SA", "PETR4.SA"]
datas_prev = ["2025-06-04", "2025-06-05", "2025-06-06", "2025-06-09", "2025-06-10"]

def criar_atributos(df):
    df = df.copy()
    df["Lag_1_Close"] = df["Close"].shift(1)
    df["Rolling_3_Close"] = df["Close"].rolling(3).mean()
    return df

def treinar_modelo(treino_df):
    features = ["Open", "High", "Low", "Volume", "Lag_1_Close", "Rolling_3_Close"]
    X = treino_df[features]
    y = treino_df["Close"]
    modelo = RandomForestRegressor(n_estimators=100, random_state=42)
    modelo.fit(X, y.values.ravel())
    return modelo

for acao in acoesSilva:
    print(f"\n--- {acao} ---")
    df = yf.download(acao, start="2020-01-01", end="2025-06-11", auto_adjust=True)

    df = df.reset_index()
    df["Date"] = pd.to_datetime(df["Date"])

    df = criar_atributos(df)

    resultados = []

    for dia in datas_prev:
        data_ref = pd.to_datetime(dia)

        treino_df = df[df["Date"] < data_ref].copy().dropna()
        teste_df = df[df["Date"] == data_ref].copy()

        if treino_df.empty or teste_df.empty:
            print(f"Sem dados suficientes para {dia}")
            continue

        try:
            modelo = treinar_modelo(treino_df)
        except Exception as e:
            print(f"Erro ao treinar modelo para {dia}: {e}")
            continue

        try:
            entrada = teste_df[["Open", "High", "Low", "Volume", "Lag_1_Close", "Rolling_3_Close"]].values
            previsto = float(modelo.predict(entrada)[0])
            real = teste_df["Close"].values[0].item()  # ✅ Corrigido aqui
            erro = real - previsto

            resultados.append({"Data": dia, "Previsto": previsto, "Real": real, "Erro": erro})

            nova_linha = teste_df.copy()
            nova_linha["Close"] = previsto
            nova_linha["Lag_1_Close"] = treino_df["Close"].iloc[-1]
            nova_linha["Rolling_3_Close"] = treino_df["Close"].iloc[-3:].mean()

            df = pd.concat([df, nova_linha], ignore_index=True)

        except Exception as e:
            print(f"Erro ao prever para {dia}: {e}")
            continue

    print("Data       | Erro (Real - Previsto)")
    for r in resultados:
        print(f"{r['Data']} | {r['Erro']:.2f}")

    if resultados:
        mse = mean_squared_error([r["Real"] for r in resultados],
                                 [r["Previsto"] for r in resultados])
        print(f"MSE (Erro Quadrático Médio) para {acao}: {mse:.4f}")
