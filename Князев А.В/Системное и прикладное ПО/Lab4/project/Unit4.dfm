object OKBottomDlg1: TOKBottomDlg1
  Left = 564
  Top = 225
  BorderStyle = bsDialog
  Caption = 'Dialog'
  ClientHeight = 173
  ClientWidth = 252
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 233
    Height = 105
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 26
    Height = 13
    Caption = #1055#1086#1083#1077
  end
  object OKBtn: TButton
    Left = 47
    Top = 132
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 127
    Top = 132
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 40
    Width = 217
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    Items.Strings = (
      'FIO'
      'GroupCode'
      'AvgMark'
      'Lang'
      'SpecName'
      'SpecCode')
  end
  object LabeledEdit1: TLabeledEdit
    Left = 16
    Top = 80
    Width = 217
    Height = 21
    EditLabel.Width = 48
    EditLabel.Height = 13
    EditLabel.Caption = #1047#1085#1072#1095#1077#1085#1080#1077
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 3
  end
end
