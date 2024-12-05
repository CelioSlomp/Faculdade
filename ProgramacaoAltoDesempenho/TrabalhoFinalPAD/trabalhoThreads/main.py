from src.app import App

if __name__ == '__main__':
    from src.app import App
    app = App(
        1000,   # FPS
        800, # Window width
        600   # Window height
    )

    app.init()