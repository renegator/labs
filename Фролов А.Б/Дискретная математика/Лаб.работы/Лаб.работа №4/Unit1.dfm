object Form1: TForm1
  Left = 251
  Top = 112
  Width = 870
  Height = 640
  Caption = #1048#1085#1080#1094#1080#1072#1083#1100#1085#1099#1081' '#1082#1086#1085#1077#1095#1085#1099#1081' '#1072#1074#1090#1086#1084#1072#1090
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 567
    Width = 862
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 862
    Height = 567
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 1
    object Splitter2: TSplitter
      Left = 1
      Top = 345
      Width = 860
      Height = 3
      Cursor = crVSplit
      Align = alTop
    end
    object Splitter3: TSplitter
      Left = 1
      Top = 377
      Width = 860
      Height = 5
      Cursor = crVSplit
      Align = alTop
    end
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 860
      Height = 344
      Align = alTop
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = []
      Lines.Strings = (
        #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1086#1073#1088#1072#1073#1086#1090#1082#1080)
      ParentFont = False
      TabOrder = 0
    end
    object s: TStringGrid
      Left = 1
      Top = 382
      Width = 860
      Height = 184
      Align = alClient
      ColCount = 4
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 1
      ColWidths = (
        64
        64
        64
        64)
    end
    object Panel2: TPanel
      Left = 1
      Top = 348
      Width = 860
      Height = 29
      Align = alTop
      Caption = 'Panel2'
      TabOrder = 2
      object Button1: TButton
        Left = 40
        Top = 3
        Width = 75
        Height = 25
        Caption = #1058#1077#1089#1090'1'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 118
        Top = 3
        Width = 75
        Height = 25
        Caption = #1058#1077#1089#1090'2'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 233
        Top = 3
        Width = 152
        Height = 25
        Caption = #1058#1077#1089#1090#1086#1074#1099#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
        TabOrder = 2
        OnClick = N2Click
      end
      object Button4: TButton
        Left = 392
        Top = 3
        Width = 185
        Height = 25
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1095#1077#1089#1082#1080#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
        TabOrder = 3
        OnClick = Button4Click
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 536
    Top = 152
    object N1: TMenuItem
      Caption = #1040#1074#1090#1086#1084#1072#1090
      object N2: TMenuItem
        Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100' '#1094#1077#1087#1086#1095#1082#1091
        OnClick = N2Click
      end
    end
  end
end
