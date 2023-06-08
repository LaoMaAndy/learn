from django.contrib import admin

# Register your models here.
from logs.models import Topic

admin.site.register(Topic)
