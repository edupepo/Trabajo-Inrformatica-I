object PantallaPrincipal: TPantallaPrincipal
  Left = 560
  Top = 371
  Width = 870
  Height = 640
  Caption = 'Pantalla Principal'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LComunicacion: TLabel
    Left = 64
    Top = 32
    Width = 232
    Height = 24
    Caption = 'Comunicacion con la tarjeta'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Shape1: TShape
    Left = 464
    Top = 128
    Width = 209
    Height = 57
  end
  object BIniciar: TButton
    Left = 56
    Top = 64
    Width = 121
    Height = 65
    Caption = 'Iniciar'
    TabOrder = 0
    OnClick = BIniciarClick
  end
  object ETemperatura: TEdit
    Left = 344
    Top = 280
    Width = 97
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object ENivel: TEdit
    Left = 344
    Top = 336
    Width = 97
    Height = 21
    TabOrder = 2
    Text = '0'
  end
  object RControlAutomatico: TRadioButton
    Left = 344
    Top = 192
    Width = 137
    Height = 41
    Caption = 'Control Automatico'
    Checked = True
    TabOrder = 3
    TabStop = True
    OnClick = RControlAutomaticoClick
  end
  object RControlManual: TRadioButton
    Left = 104
    Top = 192
    Width = 153
    Height = 41
    Caption = 'Control Manual'
    TabOrder = 4
    OnClick = RControlManualClick
  end
  object SBomba: TScrollBar
    Left = 104
    Top = 248
    Width = 161
    Height = 33
    Enabled = False
    PageSize = 0
    TabOrder = 5
  end
  object BCalefaccion: TButton
    Left = 104
    Top = 312
    Width = 145
    Height = 41
    Caption = 'Calefaccion'
    Enabled = False
    TabOrder = 6
  end
  object BValvula: TButton
    Left = 104
    Top = 376
    Width = 145
    Height = 49
    Caption = 'Valvula'
    Enabled = False
    TabOrder = 7
  end
  object Lbombam: TStaticText
    Left = 48
    Top = 256
    Width = 37
    Height = 17
    Caption = 'Bomba'
    Enabled = False
    TabOrder = 8
  end
  object LTemperaturao: TStaticText
    Left = 344
    Top = 256
    Width = 104
    Height = 17
    Caption = 'Temperatura objetivo'
    TabOrder = 9
  end
  object LNivelo: TStaticText
    Left = 344
    Top = 312
    Width = 68
    Height = 17
    Caption = 'Nivel objetivo'
    TabOrder = 10
  end
  object Timer1: TTimer
    Left = 344
    Top = 112
  end
end
