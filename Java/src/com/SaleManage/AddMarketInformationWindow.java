package com.SaleManage;

import javax.swing.*;
import java.awt.*;

public class AddMarketInformationWindow extends JDialog {
    JPanel jPanel = new JPanel(new FlowLayout(FlowLayout.CENTER,10,20));

    JLabel nameLabel = new JLabel("名称",JLabel.RIGHT);
    JTextField nameTxt = new JTextField();

    JLabel codeLabel = new JLabel("编码",JLabel.RIGHT);
    JTextField codeTxt = new JTextField();

    JLabel numLabel = new JLabel("总数",JLabel.RIGHT);
    JTextField numTxt = new JTextField();

    JLabel priceLabel = new JLabel("进价",JLabel.RIGHT);
    JTextField priceTxt = new JTextField();

    JLabel producerLabel = new JLabel("厂商",JLabel.RIGHT);
    JTextField producerTxt = new JTextField();

    JLabel dateLabel = new JLabel("入库时间",JLabel.RIGHT);
    JTextField dateTxt = new JTextField();

    JButton addButton = new JButton("添加");

    public AddMarketInformationWindow(ProductManageWindow productManageWindow) {
        super(productManageWindow,"添加销售信息",true);

        setSize(350,500);
        setLocationRelativeTo(null);
        //只销毁当前窗口
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }
}
