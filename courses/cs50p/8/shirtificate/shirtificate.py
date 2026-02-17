from fpdf import FPDF


pdf = FPDF(orientation="P", format="A4")
pdf.add_page()
pdf.set_font("helvetica", size=50)
pdf.set_font_size(24)
pdf.cell(w=None, h=55, text="CS50 Shirtificate", center=True, new_y="TOP")
pdf.image("shirtificate.png", x=10, y=70, w=190, h=190, keep_aspect_ratio=True)

with pdf.local_context(text_color=(255, 255, 255)):
    pdf.cell(w=None, h=260, text=f"{input('Name: ').strip()}", center=True)
pdf.output("shirtificate.pdf")
